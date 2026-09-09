pipeline {
    agent any

    stages {

        stage('Environment') {
            steps {
                bat 'where gcc'
                bat 'gcc --version'
                bat 'echo %PATH%'
            }
        }

    }
}