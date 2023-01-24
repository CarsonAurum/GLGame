//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_API_ERRORS_HXX
#define TITANOFAIR_API_ERRORS_HXX

typedef uint32_t TOAStatus;

// Generic Conditions               [Domain 00xx]
#define TOA_SUCCESS                     0000
#define TOA_GENERIC_FAILURE             0001

// GL Errors                        [Domain 01xx]

// App Errors                       [Domain 02xx]

// Component Errors                 [Domain 10xx]
#define TOA_COMPONENT_NOT_FOUND         1001
#define TOA_COMPONENT_PRESENT           1002
#define TOA_COMPONENT_CONFLICT          1003

// Entity Errors                    [Domain 11xx]



#endif //TITANOFAIR_API_ERRORS_HXX
