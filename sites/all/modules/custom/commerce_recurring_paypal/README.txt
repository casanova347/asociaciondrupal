This module implements Reference Transaction Using Express Checkout (billing agreement) for commerce_recurring v2 module.
It follows described steps in https://developer.paypal.com/webapps/developer/docs/classic/express-checkout/ht_ec-refTrans-SetEC-DoRefTrans-curl-etc/ to accomplish the subscription.
TODO's
=====
documentar
puede que haya que tener cuidado con la cantidad de cobros que se hacen en el cron. tardan un rato cada uno
almacenar el billing en db yt no en "variables"
mejorar la presentacion de la forma de pago. usar logos o algo. explicar que se suscribe usando su cuenta de paypal y que el dinero se extrae de su cuenta o de medios asociados a ella como cuentas bancarias o tarjetas de credito. tambien ya estaría piola que indique cada cuando se cobra (esto deberia ser un pane intermedio)

actores:
el ciclo de compra normal
el ciclo de rules y recurring para generar la enridad recurring
el ciclo de rules y recurring para ejecutar el cobro