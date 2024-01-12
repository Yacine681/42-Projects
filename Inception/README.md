# Project 42 - Dockerized Inception

## Overview

Project 42 focuses on advancing your expertise in system administration through the virtualization of various Docker images for distinct services. The deployment process utilizes Docker Compose for efficient management and orchestration.

## Components

### 1. NGINX with TLS

**Description:**
A Docker container housing the NGINX web server configured with Transport Layer Security (TLS) for secure communication.

### 2. WordPress + php-fpm

**Description:**
A Docker container combining WordPress and php-fpm for an efficient and scalable WordPress environment.

### 3. MariaDB

**Description:**
A Docker container equipped with MariaDB, a reliable and high-performance relational database.

### 4. WordPress Database Volume

**Description:**
A dedicated volume storing the WordPress database, ensuring data persistence and easy backup.

### 5. WordPress Website Files Volume

**Description:**
A separate volume containing the essential files for your WordPress website, facilitating scalable and maintainable storage.

### 6. Docker Network

**Description:**
Establishes a secure and efficient network to interconnect the Docker containers, enabling seamless communication.
