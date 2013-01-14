dnl config.m4 for extension riak

dnl ##########################################################################
dnl Initialize the extension
PHP_ARG_ENABLE(riak, whether to enable riak support,
[ --enable-rial Enable riak support])

if test "$PHP_RIAK" != "no"; then
    PHP_NEW_EXTENSION(riak, php_riak.c, $ext_shared)
fi
