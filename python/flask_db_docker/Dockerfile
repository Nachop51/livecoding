FROM python:3.11-alpine

COPY requirements.txt /tmp/requirements.txt
COPY ./app /app
# source dest
# (mi maquina) (contenedor)
WORKDIR /app

RUN apk add gcc python3-dev

RUN python3 -m pip install -r /tmp/requirements.txt

EXPOSE 5000
