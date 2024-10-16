
FROM debian:oldstable

RUN	apt-get update -y && apt-get upgrade -y

RUN apt-get install wget curl -y
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

RUN apt-get install php7.4 php-fpm php-mysqli mariadb-client -y

RUN mkdir -p /run/php/ && mkdir -p /var/www/html
RUN chown -R www-data:www-data /var/www/*

COPY    ./conf/www.conf /etc/php/7.4/fpm/pool.d
COPY    ./conf/wp-config.sh .
RUN		chmod +x wp-config.sh

ENTRYPOINT	["./wp-config.sh"]

CMD		["/usr/sbin/php-fpm7.4", "--nodaemonize"]