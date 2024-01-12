FROM debian:buster

RUN apt-get update && apt-get -y install nginx \
openssl \
&& rm -rf /var/lib/apt/lists/*

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/ssl/yabed.42.fr.pem -keyout /etc/ssl/yabed.42.fr.key -subj "/C=FR/ST=Mulhouse/L=Mulhouse/O=42 School/OU=yabed/CN=yabed.42.fr"

COPY conf/nginx.conf /etc/nginx/conf.d

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
