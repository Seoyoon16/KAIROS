#!/bin/bash

echo "1st line <$0>"

echo "2nd <$1> 3rd <$2>"

echo "4th $3, $*"

e1="my var"
echo "my var"
echo "$e1"
read e1

echo "read = " $e1

exit 0
