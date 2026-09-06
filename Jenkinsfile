pipeline {
    agent any

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
    }
}