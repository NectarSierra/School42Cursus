FROM debian:bookworm

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server mariadb-client
RUN apt-get install -y tini

COPY tools/mariadb.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/init-db.sh .

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["./init-db.sh"]
