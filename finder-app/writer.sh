if [ $# -ne 2 ]; then
	echo "Error: wrong number of arguments specified."
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p $(dirname $writefile)
echo $writestr > $writefile
