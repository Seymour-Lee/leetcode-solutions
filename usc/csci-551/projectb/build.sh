#!/bin/sh


DATE=`date '+%Y%m%d%H%M'`

docker build -t fedora:v"$DATE" -f dockerfile .  