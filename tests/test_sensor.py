import os
import subprocess
import xml.etree.ElementTree as ET

# Asegura encontrar main.exe en la raíz del proyecto
executable = os.path.join(os.getcwd(), "main.exe")

result = subprocess.run(
    [executable],
    capture_output=True,
    text=True
)

output = result.stdout

testsuite = ET.Element(
    "testsuite",
    name="Sensor Validation"
)

passed = 0
failed = 0

for line in output.splitlines():
    line = line.strip()
    
    # Evalúa si la línea corresponde a una prueba exitosa
    if line.startswith("Test") and "passed" in line:
        test_name = line.split(":")[0]  # Obtiene "Test 0 passed" o "Test 0"
        ET.SubElement(
            testsuite,
            "testcase",
            name=test_name
        )
        passed += 1

    # Evalúa si la línea corresponde a una prueba fallida
    elif line.startswith("Test") and "failed" in line:
        test_name = line.split(":")[0]
        testcase = ET.SubElement(
            testsuite,
            "testcase",
            name=test_name
        )
        failure = ET.SubElement(
            testcase,
            "failure",
            message="Test case failed"
        )
        failure.text = line
        failed += 1

testsuite.set("tests", str(passed + failed))
testsuite.set("failures", str(failed))

tree = ET.ElementTree(testsuite)
tree.write("test-results.xml", encoding="utf-8", xml_declaration=True)

print(f"Tests: {passed + failed}")
print(f"Passed: {passed}")
print(f"Failed: {failed}")
print("JUnit report generated: test-results.xml")

if result.returncode != 0:
    raise SystemExit(result.returncode)