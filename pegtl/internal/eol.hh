// Copyright (c) 2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_EOL_HH
#define PEGTL_INTERNAL_EOL_HH

#include "eol_impl.hh"
#include "skip_control.hh"

#include "../analysis/generic.hh"

namespace pegtl
{
   namespace internal
   {
      struct eol
      {
         using analyze_t = analysis::generic< analysis::rule_type::ANY >;

         template< typename Input >
         static bool match( Input & in )
         {
            return eol_impl< Input::eol >::match( in ).first;
         }
      };

      template<>
      struct skip_control< eol > : std::true_type {};

   } // namespace internal

} // namespace pegtl

#endif
