FROM debian:bookworm

RUN apt-get update -y && apt-get upgrade -y && apt-get install apt-utils -y

RUN apt-get install nginx -y && mkdir -p /etc/nginx/ssl && apt-get install openssl -y


# create key and public certificate auto signed with -x509 
# -newkey rsa:2048 generate new RSA key of 2048 bits
# -nodes 
RUN openssl req -x509 -newkey rsa:2048 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=AURA/L=Lyon/O=42/OU=42/CN=dbaule.42.fr/UID=dbaule"

COPY conf/nginx.conf /etc/nginx/sites-available/dbaule.42.fr.conf

RUN echo "include /etc/nginx/sites-available/dbaule.42.fr.conf;" > /etc/nginx/sites-enabled/dbaule.42.fr.conf

# Execute nging, -g meanwith global variable, daemon off mean execute in background 
CMD ["nginx", "-g", "daemon off;"]
