FROM debian:bookworm

# a mettre
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends apt-utils

RUN apt-get install wget -y && apt-get install php php-fpm php-mysql mariadb-client -y

# Installation du cli pour pouvoir automatiser la configuration de wordpress
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

# Donne le droit et le met ou il faut
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

# Creer le repertoire d'installation du wordpress
RUN mkdir -p /var/www/html

# Copie de la configuration de php
COPY conf/wp.conf /etc/php/8.2/fpm/pool.d/www.conf

# Copie du script de configuration de wordpress
RUN mkdir -p /var/run/wp
COPY ./tools/wp_config.sh /var/run/wp
RUN chmod +x /var/run/wp/wp_config.sh && mkdir -p /run/php

# Commence le conteneur avec le script de configuration
CMD ["sh", "/var/run/wp/wp_config.sh"]
