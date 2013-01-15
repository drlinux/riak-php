/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the MIT license. For more information, see
 * <http://www.doctrine-project.org>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>

#include "php_riak.h"
#include "client/riak_exception.h"
#include "client/riak_retry_failed_exception.h"

zend_function_entry riak_functions[] = {
    { NULL, NULL, NULL }
};


/* {{{ riak_module_entry
*/
zend_module_entry riak_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_RIAK_EXTNAME,
    riak_functions,
    PHP_MINIT(riak),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(riak),
    PHP_RIAK_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */


#ifdef COMPILE_DL_RIAK
ZEND_GET_MODULE(riak)
#endif


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(riak) {
    riak_client_RiakException(TSRMLS_C);
    riak_client_RiakRetryFailedException(TSRMLS_C);
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION
*/
PHP_MINFO_FUNCTION(riak) {
  php_info_print_table_start();

  php_info_print_table_header(2, "Riak Support", "enabled");
  php_info_print_table_row(2, "Version", PHP_RIAK_VERSION);

  php_info_print_table_end();

  DISPLAY_INI_ENTRIES();
}
/* }}} */

