// Periferico Locker
// Usado para o Mutex
//
//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_locker.h"

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
    memory = new uint8_t;
    *memory = 0;

}

/// Destructor
ac_tlm_locker::~ac_tlm_locker() {

  delete [] memory;
}

/** Internal Write
  * Note: Always write 32 bits
  * @param a is the address to write
  * @param d id the data being write
  * @returns A TLM response packet with SUCCESS
*/
ac_tlm_rsp_status ac_tlm_locker::writem( const uint32_t &d )
{
  *((uint32_t *) &memory) = *((uint32_t *) &d);
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
  *((uint32_t *) &d) = *((uint32_t *) &memory);

  return SUCCESS;
}



