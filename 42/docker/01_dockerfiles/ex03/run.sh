#!/bin/bash
docker create --name gogs-data --volume /home/gogs --volume /etc/ssh --volume /opt/gogs/custom --volume /opt/gogs/log lkaba/gogs:1.0
docker run --rm --volumes-from gogs-data -p 8080:3000 -it lkaba/gogs:1.0