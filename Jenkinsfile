pipeline {
    agent any

    environment {
        PATH = "C:\\msys64\\ucrt64\\bin;${env.PATH}"
    }

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