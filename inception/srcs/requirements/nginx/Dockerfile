FROM debian:bookworm

#install nginx and openssl
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

#ensure nginx runs as www-data with correct uid
RUN usermod -u 33 www-data && groupmod -g 33 www-data

#create ssl directory
RUN mkdir -p /etc/nginx/ssl

#copy configuration files
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/generate_ssl.sh /usr/local/bin/

#set permissions
RUN chmod +x /usr/local/bin/*.sh

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/generate_ssl.sh"]