pipeline {
    agent any

    environment {
        PATH = "C:\\msys64\\ucrt64\\bin;C:\\Users\\gall2\\AppData\\Local\\Programs\\Python\\Python313;${env.PATH}"
    }

    stages {

        stage('Build') {
            steps {
                bat 'gcc -Wall -Wextra -g -Iinclude src\\sensor.c tests\\test_sensor.c -o main.exe'
            }
        }

        stage('Test') {
            steps {
                bat 'python tests\\test_sensor.py'
            }
        }

        stage('Archive'){
            steps {
                archiveArtifacts artifacts: 'main.exe', fingerprint: true
            }
        }
    }
    post {
        always {
            junit 'test-results.xml'
        }
    }
}