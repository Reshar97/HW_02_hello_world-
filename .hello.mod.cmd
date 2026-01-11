cmd_/home/student/HW_02_hello_world/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/student/HW_02_hello_world/"$$0) }' > /home/student/HW_02_hello_world/hello.mod
