#!/bin/bash
arg1=$1
arg2=$2
name=`ls $arg2 | cut -d "." -f 1`
if [ $arg1 != "--gcc" ] && [ $arg1 != "--g++" ];then
	echo "Usage: "
	echo "$0 [gcc/c++] file"
	exit
fi
if [ $arg1 == "--gcc" ];then
	ch="gcc"
else 
	ch="g++"
fi
$ch $arg2 -o $name.c 
sha=`md5sum $arg2 | cut -d " " -f 1`
while true; do
	if [ `md5sum $arg2 | cut -d " " -f 1` != $sha ];then
		$ch $arg2 -o $name.c
		sha=`md5sum $arg2 | cut -d " " -f 1` 
	fi
done
