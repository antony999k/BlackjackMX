//
//  operationCodes.h
//  BlackjackMX
//
//  Created by Antony Morales on 05/04/19.
//  Copyright © 2019 Antony999k. All rights reserved.
//

#ifndef operationCodes_h
#define operationCodes_h

// The different types of sockets operation available
typedef enum valid_operations {INIT, MOVEMENT, ERROR, EXIT} operation_t;

// The different types of game operations available
typedef enum valid_game_operations {SPLIT, DOUBLE, HIT, STAND, SURRENDER} game_operation_t;

#endif /* operationCodes_h */
