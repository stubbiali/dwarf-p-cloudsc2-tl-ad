INTERFACE
SUBROUTINE CUADJTQSAD&
 & (KIDIA, KFDIA, KLON, KLEV,&
 & KK,&
 & PSP5, PT5, PQ5,&
 & PSP, PT, PQ, LDFLAG, KCALL,  YDCST, YDTHF) 
USE PARKIND1 ,ONLY : JPIM ,JPRB
USE YOMCST   , ONLY : TOMCST
USE YOETHF   , ONLY : TOETHF
INTEGER(KIND=JPIM),INTENT(IN) :: KLON
INTEGER(KIND=JPIM),INTENT(IN) :: KLEV
INTEGER(KIND=JPIM),INTENT(IN) :: KIDIA
INTEGER(KIND=JPIM),INTENT(IN) :: KFDIA
INTEGER(KIND=JPIM),INTENT(IN) :: KK
REAL(KIND=JPRB) ,INTENT(IN) :: PSP5(KLON)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PT5(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PQ5(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PSP(KLON)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PT(KLON,KLEV)
REAL(KIND=JPRB) ,INTENT(INOUT) :: PQ(KLON,KLEV)
LOGICAL ,INTENT(IN) :: LDFLAG(KLON)
INTEGER(KIND=JPIM),INTENT(IN) :: KCALL
TYPE(TOMCST)      ,INTENT(IN) :: YDCST
TYPE(TOETHF)      ,INTENT(IN) :: YDTHF
END SUBROUTINE CUADJTQSAD
END INTERFACE
