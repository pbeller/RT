#! /bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

function test_return_ok()
{
	if [ $? == 0 ];then
		echo "$GREEN""OK""$NC"
	else
		echo "$RED""NOK""$NC"
	fi
	return
}

function test_return_nok()
{
	if [ $? == 0 ];then
		echo "$RED""NOK""$NC"
	else
		echo "$GREEN""OK""$NC"
	fi
	return
}


make
printf "TEST WITH A FILE DOES NOT EXIST\n"
./rt "BONJOUR" 2>&1 | grep -q "BONJOUR file does not exist"
test_return_ok
./rt "BONJOUR" 2> /dev/null
test_return_nok
