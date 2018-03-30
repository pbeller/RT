#! /bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

function test_return_ok()
{
	if [ $? == 0 ];then
		printf " $GREEN""OK""$NC"
	else
		printf " $RED""NOK""$NC"
	fi
	printf "\n"
	return
}

function test_return_nok()
{
	if [ $? == 0 ];then
		printf " $RED""NOK""$NC"
	else
		printf " $GREEN""OK""$NC"
	fi
	printf "\n"
	return
}


make
printf "Test missing light data."
./rt scenes/scene_missing_light_data.json > /dev/null
test_return_ok

printf "Test missing camera data."
./rt scenes/scene_missing_camera_data.json > /dev/null
test_return_ok

printf "Test missing object data."
./rt scenes/scene_missing_object_data.json > /dev/null
test_return_ok

printf "Test invalid type."
./rt scenes/scene_invalid_type.json > /dev/null
test_return_ok

printf "Test empty value"
./rt scenes/scene_empty_value.json > /dev/null
test_return_ok

printf "Test multiple value"
./rt scenes/scene_multiple_values.json > /dev/null
test_return_ok
