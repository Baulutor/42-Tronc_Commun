FROM debian:oldstable

RUN	apt-get update -y && apt-get upgrade -y

RUN	apt-get install openssl nginx -y

RUN	mkdir /etc/nginx/certs

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-keyout /etc/nginx/certs/nginx.key -out /etc/nginx/certs/nginx.crt \
	-subj "/C=FR/L=Lyon/O=42/OU=dbaule/CN=dbaule.42.fr"

COPY conf/nginx.conf /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]