FROM php:8.2-fpm-alpine3.17

# docker build -f docker/php/Dockerfile -t serginhold/cpp-php:latest .
# docker exec -i -t cpp-php sh
# docker exec -i -t cpp-php bash

RUN apk add --no-cache bash shadow git linux-headers


RUN apk add --no-cache g++ make
RUN git clone --branch v3.0.0 https://github.com/fast-debug/PHP-CPP /tmp/php-cpp \
    && cd /tmp/php-cpp \
    && make \
    && make install \
    && rm -rf /tmp/php-cpp


WORKDIR /var/www
ENV DOCKER_APP_UID=1000
RUN usermod -u $DOCKER_APP_UID www-data
USER www-data
