pipeline {
    agent any

    environment {
        PATH = "C:\\msys64\\ucrt64\\bin;${env.PATH}"
    }

    stages {

        stage('Build') {
            steps {
                bat 'gcc -Wall -Wextra -g main.c sensor.c -o main.exe'
            }
        }
        
        stage('Test') {
            steps {
                bat 'main.exe'
            }
        }

        stage('Archive'){
            steps {
                archiveArtifacts artifacts: 'main.exe', fingerprint: true
            }
        }
    }
}