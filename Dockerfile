FROM gcc:4.9
COPY . /usr/src/names-database
WORKDIR /usr/src/names-database
RUN gcc -o names-database main.c
CMD ["./names-database"]