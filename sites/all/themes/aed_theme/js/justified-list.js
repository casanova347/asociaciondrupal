// @todo empaquetar esta solucion junto a _justified_list.scss
// En template.php hay preprocess que indican qué fields contienen
// listas que han de ser listas justificadas. este script les aplica el class correspondiente.
$(".make-justified-list > .field-items").addClass("justified-list");
// Workaround!. Las listas justificadas van a fallar si no tienen un \n entre sus elementos.
$(".justified-list > *").after("\n");
