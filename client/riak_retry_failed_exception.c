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

#include <php.h>
#include <zend_exceptions.h>

#include "client/riak_exception.h"
#include "client/riak_retry_failed_exception.h"

extern PHPAPI zend_class_entry *riak_ce_riak_client_riak_retry_failed_exception;
 
void riak_client_RiakRetryFailedException(TSRMLS_D) {
    zend_class_entry e;
 
    INIT_NS_CLASS_ENTRY(e, "Riak\\Client", "RiakRetryFailedException", NULL);

    riak_ce_riak_client_riak_retry_failed_exception = zend_register_internal_class_ex(&e, riak_ce_riak_client_riak_exception, NULL TSRMLS_CC);

    riak_ce_riak_client_riak_retry_failed_exception->create_object = riak_ce_riak_client_riak_exception;
}
