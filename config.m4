dnl config.m4 for extension riak

dnl ##########################################################################
dnl Initialize the extension
PHP_ARG_ENABLE(riak, whether to enable riak support,
[ --enable-rial Enable riak support])

if test "$PHP_RIAK" != "no"; then
    PHP_NEW_EXTENSION(riak, php_riak.c \
        client/riak_exception.c \
        client/riak_retry_failed_exception.c, $ext_shared)
    PHP_ADD_BUILD_DIR($ext_builddir/client)
fi
