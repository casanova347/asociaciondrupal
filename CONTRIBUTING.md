#Contribuir en la web de la AED

Para contribuir en este repo, inicialmente tienes que seguir estos pasos:

## Preparar el entorno de desarrollo
- Haz un fork del repo [[Puedes hacerlo clickeando este enlace](https://github.com/AsociacionDrupalES/asociaciondrupal/fork)]
- Ya en tu fork clona el repo a tu ordenador y cambiate a la rama "dev" (**git checkout origin dev**)
- Tienes que crear el settings.php. Utilizamos un settings de lo mas normal así que solo configura la DB y listo.
- Habla con el organizador para que te pase una copia de la DB (@capynet, @jsbalsera).

## Ahora si, "como echar una mano"

[Echa un vistazo a los issues](https://github.com/AsociacionDrupalES/asociaciondrupal/issues) y si ves que puedes hacer alguno asignatelo y dale caña!

###Notas útiles
Para entrar como admin recuerda que desde la consola con "**drush uli**" puedes loguearte.
Cualquier parche que crees o uses ponlo en "UTIL/patches/[MODULO]" junto a un readme.txt que indique el nombre del parche y que cosa soluciona. Puedes tomar ejemplo de los que ya hay.

###dev.asociaciondrupal.es 
Es nuestro entorno de desarrollo/integración.
**htpasswd:**  aed / d3v3l0p3r$

Una vez importada la db habilita el módulo "stage_file_proxy" y setea "http://asociaciondrupal.es":

`drush en stage_file_proxy -y`

`drush vset stage_file_proxy_origin "http://asociaciondrupal.es"`
