// Periferico Locker
// Usado para o Mutex
//
//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_locker.h"

#define CHANGE_ENDIAN(value) (0x00000000 | (value << 24) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x0000FF00) | (value >> 24))
#define LOCK_ADDR ( 6 * 1024 * 1024 )

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_locker;

/// Constructor
ac_tlm_locker::ac_tlm_locker( sc_module_name module_name ) :
  sc_module( module_name ),
  target_export("iport")
{
    /// Binds target_export to the memory
    target_export( *this );

    /// Initialize memory vector
    memory = 0;

}

/// Destructor
ac_tlm_locker::~ac_tlm_locker() {

  //delete memory;
}

/** Internal Write
  * Note: Always write 32 bits
  * @param a is the address to write
  * @param d id the data being write
*/
ac_tlm_rsp_status ac_tlm_locker::writem( const uint32_t &d )
{
  memory = CHANGE_ENDIAN(d);
  return SUCCESS;
}

/** Internal Read
  * Note: Always read 32 bits
  * @param a is the address to read
  * @param d id the data that will be read
  * @returns A TLM response packet with SUCCESS and a modified d
*/
ac_tlm_rsp_status ac_tlm_locker::readm( uint32_t &d )
{
  *((uint32_t *) &d) = CHANGE_ENDIAN(memory);
  return SUCCESS;
}



