## 42 - WebServ

The project's objective is to construct an HTTP web server in compliance with C++98 standards. This web server is designed to manage various HTTP requests, including GET, HEAD, POST, PUT, and DELETE. It has the capability to serve static files from a defined root directory and generate dynamic content using CGI. Additionally, the server is engineered to handle concurrent connections from multiple clients by leveraging the select() function.

## Usage
   ```shell
# Run The Server
 make && ./webserv [conifg_file] ## Leave empty for default configuration.
   ```
