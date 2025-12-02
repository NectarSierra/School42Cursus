FROM debian:bookworm

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y wget php-fpm php-mysql
RUN apt-get install -y tini

RUN wget https://wordpress.org/wordpress-6.8.3.tar.gz
RUN tar -xzvf wordpress-6.8.3.tar.gz

COPY tools/wp-config.php /wordpress

WORKDIR /wordpress

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["php", "-S", "0.0.0.0:9000"]
