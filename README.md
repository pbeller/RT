# RT

Cloner la libtowel dans le dossier libs

```
cd
git clone https://github.com/juschaef/libtowel.git
cd -
```

build avec make

lancer rt avec le fichier scene.json

```
./rt scenes/scene.json
```

la minilibx est celle pour el capitain, penser a la changer en cas d'autre version


Fichiers de test du parser de scenes
```
./rt scenes/scene_missing_light_data.json > /dev/null
./rt scenes/scene_missing_camera_data.json > /dev/null
./rt scenes/scene_missing_object_data.json > /dev/null
./rt scenes/scene_invalid_type.json > /dev/null
./rt scenes/scene_empty_value.json > /dev/null
./rt scenes/scene_multiple_values.json
```

Parsing d'argument disponible
```
./rt -h
```

Lecture de fichier via STDIN disponible
```
cat scenes/scene.json | ./rt
./rt < scenes/scene.json
```
