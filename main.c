/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:29:36 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 13:06:06 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ft_printf.h"

int	main(void)
{
	ft_printf("c type >\n");
	printf("og		    c:%c$\n", '0');
	printf("og		   4c:%4c$\n", '0');
	printf("og		  -4c:%-4c$\n", '0');
		ft_printf("\n");
	ft_printf("ft		    c:%c$\n", '0');
	ft_printf("ft		   4c:%4c$\n", '0');
	ft_printf("ft		  -4c:%-4c$\n", '0');
	ft_printf("n/a - og\n");
	ft_printf("ft		  04c:%04c$\n", '0');
	ft_printf("ft		 4.4c:%4.4c$\n", '0');
	ft_printf("ft		  #4c:%#4c$\n", '0');
	ft_printf("ft		  '4c:%'4c$\n", '0');
	ft_printf("ft		  +4c:%+4c$\n", '0');
	ft_printf("ft		 324c:% 4c$\n", '0');

	ft_printf("\ns type >\n");
	printf("og		    s:%s$\n", "abcde");
	printf("og		   4s:%4s$\n", "abcde");
	printf("og		   8s:%8s$\n", "abcde");
	printf("og		  -8s:%-8s$\n", "abcde");
	printf("og		 4.4s:%4.4s$\n", "abcde");
	printf("og		  .2s:%.2s$\n", "abcde");
	printf("og		  .7s:%.7s$\n", "abcde");
		ft_printf("\n");
	ft_printf("ft		    s:%s$\n", "abcde");
	ft_printf("ft		   4s:%4s$\n", "abcde");
	ft_printf("ft		   8s:%8s$\n", "abcde");
	ft_printf("ft		  -8s:%-8s$\n", "abcde");
	ft_printf("ft		 4.4s:%4.4s$\n", "abcde");
	ft_printf("ft		  .2s:%.2s$\n", "abcde");
	ft_printf("ft		  .7s:%.7s$\n", "abcde");
	ft_printf("n/a - og\n");
	ft_printf("ft		  08s:%08s$\n", "abcde");
	ft_printf("ft		  #8s:%#8s$\n", "abcde");
	ft_printf("ft		  +8s:%+8s$\n", "abcde");
	ft_printf("ft		  '8s:%'8s$\n", "abcde");
	ft_printf("ft		 328s:% 8s$\n", "abcde");

	ft_printf("\ni type pos>\n");
	printf("og		    i:%i$\n", 456);
	printf("og		   2i:%2i$\n", 456);
	printf("og		  +4i:%+4i$\n", 456);
	printf("og		   5i:%5i$\n", 456);
	printf("og		 325i:% 5i$\n", 456);
	printf("og		  +5i:%+5i$\n", 456);
	printf("og		  -5i:%-5i$\n", 456);
	printf("og		  05i:%05i$\n", 456);
	printf("og		 -+5i:%-+5i$\n", 456);
	printf("og		 0+5i:%0+5i$\n", 456);
	printf("og		  '8i:%'5i$\n", 45456);
		ft_printf("\n");
	ft_printf("ft		    i:%i$\n", 456);
	ft_printf("ft		   2i:%2i$\n", 456);
	ft_printf("ft		  +4i:%+4i$\n", 456);
	ft_printf("ft		   5i:%5i$\n", 456);
	ft_printf("ft		 325i:% 5i$\n", 456);
	ft_printf("ft		  +5i:%+5i$\n", 456);
	ft_printf("ft		  -5i:%-5i$\n", 456);
	ft_printf("ft		  05i:%05i$\n", 456);
	ft_printf("ft		 -+5i:%-+5i$\n", 456);
	ft_printf("ft		 0+5i:%0+5i$\n", 456);
	ft_printf("ft		  '8i:%'5i$\n", 45456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  #5i:%#5i$\n", 456);

	ft_printf("\ni type neg>\n");
	printf("og		    i:%i$\n", -456);
	printf("og		   2i:%2i$\n", -456);
	printf("og		  +4i:%+4i$\n", -456);
	printf("og		   5i:%5i$\n", -456);
	printf("og		 325i:% 5i$\n", -456);
	printf("og		  +5i:%+5i$\n", -456);
	printf("og		  -5i:%-5i$\n", -456);
	printf("og		  05i:%05i$\n", -456);
	printf("og		 -+5i:%-+5i$\n", -456);
	printf("og		 0+5i:%0+5i$\n", -456);
	printf("og		  '8i:%'5i$\n", -45456);
		ft_printf("\n");
	ft_printf("ft		    i:%i$\n", -456);
	ft_printf("ft		   2i:%2i$\n", -456);
	ft_printf("ft		  +4i:%+4i$\n", -456);
	ft_printf("ft		   5i:%5i$\n", -456);
	ft_printf("ft		 325i:% 5i$\n", -456);
	ft_printf("ft		  +5i:%+5i$\n", -456);
	ft_printf("ft		  -5i:%-5i$\n", -456);
	ft_printf("ft		  05i:%05i$\n", -456);
	ft_printf("ft		 -+5i:%-+5i$\n", -456);
	ft_printf("ft		 0+5i:%0+5i$\n", -456);
	ft_printf("ft		  '8i:%'5i$\n", -45456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  #5i:%#5i$\n", -456);

	ft_printf("\nu type pos>\n");
	printf("og		    u:%u$\n", 456);
	printf("og		   2u:%2u$\n", 456);
	printf("og		   5u:%5u$\n", 456);
	printf("og		  -5u:%-5u$\n", 456);
	printf("og		  05u:%05u$\n", 456);
	printf("og		  '8u:%'5u$\n", 45456);
		ft_printf("\n");
	ft_printf("ft		    u:%u$\n", 456);
	ft_printf("ft		   2u:%2u$\n", 456);
	ft_printf("ft		   5u:%5u$\n", 456);
	ft_printf("ft		  -5u:%-5u$\n", 456);
	ft_printf("ft		  05u:%05u$\n", 456);
	ft_printf("ft		  '8u:%'5u$\n", 45456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  +4u:%+4u$\n", 456);
	ft_printf("ft		 325u:% 5u$\n", 456);
	ft_printf("ft		  +5u:%+5u$\n", 456);
	ft_printf("ft		 -+5u:%-+5u$\n", 456);
	ft_printf("ft		 0+5u:%0+5u$\n", 456);
	ft_printf("ft		  #5u:%#5u$\n", 456);

	ft_printf("\nu type neg>\n");
	printf("og		    u:%u$\n", -456);
	printf("og		   2u:%2u$\n", -456);
	printf("og		   5u:%5u$\n", -456);
	printf("og		  -5u:%-5u$\n", -456);
	printf("og		  05u:%05u$\n", -456);
	printf("og		  '8u:%'5u$\n", -45456);
		ft_printf("\n");
	ft_printf("ft		    u:%u$\n", -456);
	ft_printf("ft		   2u:%2u$\n", -456);
	ft_printf("ft		   5u:%5u$\n", -456);
	ft_printf("ft		  -5u:%-5u$\n", -456);
	ft_printf("ft		  05u:%05u$\n", -456);
	ft_printf("ft		  '8u:%'5u$\n", -45456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  +4u:%+4u$\n", -456);
	ft_printf("ft		 325u:% 5u$\n", -456);
	ft_printf("ft		  +5u:%+5u$\n", -456);
	ft_printf("ft		 -+5u:%-+5u$\n", -456);
	ft_printf("ft		 0+5u:%0+5u$\n", -456);
	ft_printf("ft		  #5u:%#5u$\n", -456);

	ft_printf("\nx type pos>\n");
	printf("og		    x:%x$\n", 456);
	printf("og		   2x:%2x$\n", 456);
	printf("og		   5x:%5x$\n", 456);
	printf("og		  -5x:%-5x$\n", 456);
	printf("og		  05x:%05x$\n", 456);
	printf("og		  #5x:%#5x$\n", 456);
	printf("og		 #09x:%#09x$\n", 456);
	printf("og		  #9x:%#9x$\n", 456);
		ft_printf("\n");
	ft_printf("ft		    x:%x$\n", 456);
	ft_printf("ft		   2x:%2x$\n", 456);
	ft_printf("ft		   5x:%5x$\n", 456);
	ft_printf("ft		  -5x:%-5x$\n", 456);
	ft_printf("ft		  05x:%05x$\n", 456);
	ft_printf("ft		  #5x:%#5x$\n", 456);
	ft_printf("ft		 #09x:%#09x$\n", 456);
	ft_printf("ft		  #9x:%#9x$\n", 456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  '8x:%'5x$\n", 456);
	ft_printf("ft		  +4x:%+4x$\n", 456);
	ft_printf("ft		 325x:% 5x$\n", 456);
	ft_printf("ft		  +5x:%+5x$\n", 456);
	ft_printf("ft		 -+5x:%-+5x$\n", 456);
	ft_printf("ft		 0+5x:%0+5x$\n", 456);

	ft_printf("\nx type neg>\n");
	printf("og		    x:%x$\n", -456);
	printf("og		   2x:%2x$\n", -456);
	printf("og		  10x:%10x$\n", -456);
	printf("og		 -10x:%-10x$\n", -456);
	printf("og		 010x:%010x$\n", -456);
	printf("og		 #10x:%#10x$\n", -456);
	printf("og		#015x:%#015x$\n", -456);
	printf("og		 #15x:%#15x$\n", -456);
		ft_printf("\n");
	ft_printf("ft		    x:%x$\n", -456);
	ft_printf("ft		   2x:%2x$\n", -456);
	ft_printf("ft		  10x:%10x$\n", -456);
	ft_printf("ft		 -10x:%-10x$\n", -456);
	ft_printf("ft		 010x:%010x$\n", -456);
	ft_printf("ft		 #10x:%#10x$\n", -456);
	ft_printf("ft		#015x:%#015x$\n", -456);
	ft_printf("ft		 #15x:%#15x$\n", -456);
	ft_printf("n/a - og\n");
	ft_printf("ft		  '8x:%'8x$\n", -456);
	ft_printf("ft		 +10x:%+10x$\n", -456);
	ft_printf("ft		3210x:% 10x$\n", -456);
	ft_printf("ft		 +10x:%+10x$\n", -456);
	ft_printf("ft		-+10x:%-+10x$\n", -456);
	ft_printf("ft		0+10x:%0+10x$\n", -456);

	return (0);
}*/
