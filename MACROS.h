/*
 * MACROS.h
 *
 * Created: 10/13/2017 9:55:28 AM
 *  Author: Hamdy
 */

#ifndef MACROS_H_
#define MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG, BIT) (REG |= (1 << BIT))
/* Clear a certain bit in any register */
#define CLEAR_BIT(REG, BIT) (REG &= (~(1 << BIT)))
/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG, BIT) (REG ^= (1 << BIT))
/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG, BIT) (REG & (1 << BIT))
/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG, BIT) (!(REG & (1 << BIT)))

/* Assign a value to a certain bit in any register */
#define ASSIGN_BIT(REG, BIT, VALUE) \
   do                               \
   {                                \
      CLEAR_BIT(REG, BIT);          \
      REG |= ((VALUE) << BIT);      \
   } while (0)

#define GET_BIT(REG, BIT) ((REG & (1 << BIT)) >> BIT)

#define SET_MASK(REG, MASK) (REG != MASK)

#define CLEAR_MASK(REG, MASK) (REG &= (~MASK))

#endif /* MACROS_H_ */