# i n c l u d e   " B a s i c T a n k . h "  
 # i n c l u d e   " B r i c k . h "  
 # i n c l u d e   " F a s t T a n k . h "  
 # i n c l u d e   " P l a y e r B u l l e t . h "  
  
 # i n c l u d e   < Q O b j e c t >  
 # i n c l u d e   < Q G r a p h i c s P i x m a p I t e m >  
 # i n c l u d e   < Q G r a p h i c s S c e n e >  
 # i n c l u d e   < Q L i s t >  
 # i n c l u d e   < Q D e b u g >  
 # i n c l u d e   < Q T i m e r >  
  
 P l a y e r B u l l e t : : P l a y e r B u l l e t ( T a n k   * t a n k )   :   B u l l e t ( t a n k )   {  
         s e t P i x m a p ( Q P i x m a p ( " : / i m a g e s / I m a g e s / b u l l e t . p n g " ) ) ;  
  
         t i m e r   =   n e w   Q T i m e r ( t h i s ) ;  
         c o n n e c t ( t i m e r ,   & Q T i m e r : : t i m e o u t ,   t h i s ,   & B u l l e t : : m o v e ) ;  
         t i m e r - > s t a r t ( 5 0 ) ;  
  
         P a r e n t   =   t a n k ;  
 }  
 v o i d   P l a y e r B u l l e t : : m o v e ( )   {  
  
         Q L i s t < Q G r a p h i c s I t e m   * >   c o l l i d i n g _ i t e m s   =   c o l l i d i n g I t e m s ( ) ; / / ������o ���������������M ���� 
         f o r e a c h   ( Q G r a p h i c s I t e m   * i t e m ,   c o l l i d i n g _ i t e m s )   { / / ������C ����i t e m ������O e n e m y  
                 B r i c k   *   b r i c k   =   d y n a m i c _ c a s t < B r i c k * > ( i t e m ) ; / / ���
��A ������O e n e m y ��h ���^ n o n e  
                 i f   ( b r i c k )   {  
  
                         / /   R e m o v e   f r o m   t h e   s c e n e   f i r s t  
                         s c e n e ( ) - > r e m o v e I t e m ( b r i c k ) ;  
                         s c e n e ( ) - > r e m o v e I t e m ( t h i s ) ;  
                         / /   D e l e t e   f r o m   t h e   m e m o r y  
                         d e l e t e   b r i c k ;  
                         P a r e n t - > s e t I s B u l l e t I n S c e n e ( f a l s e ) ;  
                         r e t u r n ;   / /   i m p o r t a n t  
                 }  
         }  
  
         i f ( x ( ) > 1 5   & &   x ( ) < 4 7 5   & &   y ( ) > 1 5   & &   y ( ) < 3 1 5 ) {  
  
                 / /   C h e c k   f o r   c o l l i s i o n s   w i t h   b r i c k s  
                 Q L i s t < Q G r a p h i c s I t e m * >   c o l l i d i n g _ i t e m s   =   c o l l i d i n g I t e m s ( ) ;  
  
                 f o r e a c h   ( Q G r a p h i c s I t e m   * i t e m ,   c o l l i d i n g _ i t e m s )   {  
                         i f   ( d y n a m i c _ c a s t < B r i c k * > ( i t e m ) )   {  
                                 / /   C o l l i d e d   w i t h   a   b r i c k ,   r e m o v e   b o t h   t h e   b u l l e t   a n d   t h e   b r i c k  
                                 s c e n e ( ) - > r e m o v e I t e m ( t h i s ) ;  
                                 P a r e n t - > s e t I s B u l l e t I n S c e n e ( 0 ) ;  
  
                                 / /   R e m o v e   b r i c k   f r o m   t h e   s c e n e  
  
                                 / / s c e n e ( ) - > r e m o v e I t e m ( i t e m ) ;   / / ��| c r a s h e d  
                                 / / d e l e t e   i t e m ;     / /   o p t i o n a l ,   i f   y o u   w a n t   t o   f r e e   m e m o r y  
  
                         }  
                         i f   ( d y n a m i c _ c a s t < B a s i c T a n k * > ( i t e m ) )   {  
                                 / /   C o l l i d e d   w i t h   a   b r i c k ,   r e m o v e   b o t h   t h e   b u l l e t   a n d   t h e   b r i c k  
                                 s c e n e ( ) - > r e m o v e I t e m ( t h i s ) ;  
                                 P a r e n t - > s e t I s B u l l e t I n S c e n e ( 0 ) ;  
                                 d e l e t e   i t e m ;  
                         }  
                         b r e a k ;  
                 }  
  
                 i f ( R o t a t i o n   = =   0 ) {  
                         s e t P o s ( x ( ) ,   y ( ) - 8 ) ;  
                 } e l s e   i f ( R o t a t i o n   = =   9 0 ) {  
                         s e t P o s ( x ( ) + 8 ,   y ( ) ) ;  
                 } e l s e   i f ( R o t a t i o n   = =   1 8 0 ) {  
                         s e t P o s ( x ( ) ,   y ( ) + 8 ) ;  
                 } e l s e   i f ( R o t a t i o n   = =   2 7 0 ) {  
                         s e t P o s ( x ( ) - 8 ,   y ( ) ) ;  
                 }  
         } e l s e {  
                 i f   ( s c e n e ( )   ! =   n u l l p t r )   {  
                         s c e n e ( ) - > r e m o v e I t e m ( t h i s ) ;  
                         P a r e n t - > s e t I s B u l l e t I n S c e n e ( 0 ) ;  
                 }  
         }  
 }  
 