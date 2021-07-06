/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:40:16 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/05 23:53:07 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    main(int x)
{
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...

x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
return x & 0x7f;
}
