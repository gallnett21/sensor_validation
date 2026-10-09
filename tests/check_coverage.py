COVERAGE_THRESHOLD = 85.0

with open("coverage-summary.txt", "r", encoding="utf-8") as file:
    lines = file.readlines()

coverage = None
for line in lines:
    if "Lines executed:" in line:
        coverage = float(line.split(":")[1].split("%")[0])
        print(f"Coverage detected: {coverage}")
        print(f"Coverage Threshold: {COVERAGE_THRESHOLD}")

        if coverage >= COVERAGE_THRESHOLD:
            print("Quality gate PASSED")
        else:
            print("Quality gate FAILED")
            raise SystemExit(1)
        break

if coverage is None:
    print("ERROR: Coverage data not found")
    raise SystemExit(1)