FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

#create directories
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 755 /var/run/mysqld

#to copy the configuration
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/init_db.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/init_db.sh

#enviroment variables
ENV MYSQL_DATABASE=app_db \
    MYSQL_USER=app_user

EXPOSE 3306

ENTRYPOINT ["init_db.sh"]
