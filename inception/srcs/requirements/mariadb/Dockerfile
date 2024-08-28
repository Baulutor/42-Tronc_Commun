FROM debian:bookworm

RUN apt-get update -y && apt-get upgrade -y && apt-get install mariadb-server -y


ARG DATABASE
ARG DATA_USER
ARG PASS
ARG ROOT_PASS
 
#give all access to root
RUN service mariadb start && mariadb -e  "GRANT ALL PRIVILEGES ON * . * TO 'root'@'localhost';" \
&& mariadb -e "FLUSH PRIVILEGES;" 

RUN service mariadb start && mariadb -e "CREATE DATABASE IF NOT EXISTS ${DATABASE};" \
&& mariadb -e "CREATE USER IF NOT EXISTS '${DATA_USER}'@'localhost' IDENTIFIED BY '${PASS}';" \
&& mariadb -e "GRANT ALL PRIVILEGES ON ${DATABASE}.* to '${DATA_USER}'@'%' IDENTIFIED BY '${PASS}';" \
&& mariadb -e "FLUSH PRIVILEGES;" 


# --bind-address=0.0.0.0 give access to all network interface 
CMD ["mariadbd", "--bind-address=0.0.0.0"]
