# set -x

if [ $# -ne 2 ]; then
	echo "Error: wrong number of arguments specified."
	exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d $filesdir ]; then
	echo "Error: not a directory: $filesdir"
	exit 1
fi

number_of_files=$(find "$filesdir" -type f | wc --lines)
number_of_matches=$(find "$filesdir" -type f | xargs grep $searchstr | wc --lines)
echo "The number of files are $number_of_files and the number of matching lines are $number_of_matches"
