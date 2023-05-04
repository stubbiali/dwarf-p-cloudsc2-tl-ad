!*
!     ------------------------------------------------------------------
!     TANGENT LINEAR OF THERMODYNAMICAL FUNCTIONS .

!     Pressure of water vapour at saturation
!        INPUT : PTARET = TEMPERATURE PERTURBATION
!                PTARE5 = TRAJECTORY TEMPERATURE
!                PALFATL= TL OF THE ALFA OPERATOR
REAL(KIND=JPRB) :: FESW,FESI,FESWTL,FESITL,FOEEWMTL,FOEEWMOTL
REAL(KIND=JPRB) :: FOEALFATL,FOEALFCUTL,FOELHMTL,FOELHMCUTL
REAL(KIND=JPRB) :: FOEEWMCUTL
REAL(KIND=JPRB) :: PTARET,PTARE5,PALFATL

FESW(PTARET) =  _PREFIX2_ R2ES * EXP( _PREFIX2_ R3LES*(PTARET- _PREFIX1_ RTT)/(PTARET- _PREFIX2_ R4LES))
FESI(PTARET) =  _PREFIX2_ R2ES * EXP( _PREFIX2_ R3IES*(PTARET- _PREFIX1_ RTT)/(PTARET- _PREFIX2_ R4IES))

FESWTL(PTARET,PTARE5) =  _PREFIX2_ R3LES*( _PREFIX1_ RTT- _PREFIX2_ R4LES)/(PTARE5- _PREFIX2_ R4LES)**2 *&
                      &PTARET * FESW(PTARE5)
FESITL(PTARET,PTARE5) =  _PREFIX2_ R3IES*( _PREFIX1_ RTT- _PREFIX2_ R4IES)/(PTARE5- _PREFIX2_ R4IES)**2 *&
                      &PTARET * FESI(PTARE5)
FOEEWMTL(PTARET,PTARE5,PALFATL) =&
                  &FOEALFA(PTARE5)*FESWTL(PTARET,PTARE5) +&
                  &FESW(PTARE5)*PALFATL +&
                  &(1.0_JPRB-FOEALFA(PTARE5))*FESITL(PTARET,PTARE5) -&
                  &FESI(PTARE5)*PALFATL

FOEEWMCUTL(PTARET,PTARE5,PALFATL) =&
                  &FOEALFCU(PTARE5)*FESWTL(PTARET,PTARE5) +&
                  &FESW(PTARE5)*PALFATL +&
                  &(1.0_JPRB-FOEALFCU(PTARE5))*FESITL(PTARET,PTARE5) -&
                  &FESI(PTARE5)*PALFATL

FOEEWMOTL(PTARET,PTARE5)=FESWTL(PTARET,PTARE5)

FOEALFATL(PTARET,PTARE5) = (0.5_JPRB+SIGN(0.5_JPRB,PTARE5- _PREFIX2_ RTICE)) &
              & * (0.5_JPRB-SIGN(0.5_JPRB,PTARE5- _PREFIX2_ RTWAT)) & 
              & * 2.0_JPRB*(PTARE5- _PREFIX2_ RTICE)*PTARET/( _PREFIX2_ RTWAT- _PREFIX2_ RTICE)**2

FOEALFCUTL(PTARET,PTARE5) = (0.5_JPRB+SIGN(0.5_JPRB,PTARE5- _PREFIX2_ RTICECU)) &
              & * (0.5_JPRB-SIGN(0.5_JPRB,PTARE5- _PREFIX2_ RTWAT)) & 
              & * 2.0_JPRB*(PTARE5- _PREFIX2_ RTICECU)*PTARET*( _PREFIX2_ RTWAT_RTICECU_R)**2

FOELHMTL(PTARET,PTARE5) = FOEALFATL(PTARET,PTARE5)*( _PREFIX1_ RLVTT- _PREFIX1_ RLSTT)

FOELHMCUTL(PTARET,PTARE5) = FOEALFCUTL(PTARET,PTARE5)*( _PREFIX1_ RLVTT- _PREFIX1_ RLSTT)
