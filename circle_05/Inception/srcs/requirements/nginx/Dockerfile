FROM debian:bookworm

RUN apt-get update && apt-get upgrade
RUN apt-get install -y nginx
RUN apt-get install -y tini

RUN rm -rf /etc/nginx/sites-enabled/default
COPY ./tools/my_config.conf /etc/nginx/conf.d/

EXPOSE 80
EXPOSE 443

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["nginx", "-g", "daemon off;"]
