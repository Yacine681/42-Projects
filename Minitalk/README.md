## 42 - Minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

- The client will send information (a string) to the server using UNIX signals. 
- The server must correctly receive and interpret this information, then display it.

## Usage
 ```shell
 $ ./server
 PID: <PID_SERVER>
 
 (wait)
 ```

 ```shell
 $ ./client <PID_SERVER> <STRING>
 ```