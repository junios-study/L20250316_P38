// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSHUD.h"
#include "Engine/Canvas.h"

void ATPSHUD::DrawHUD()
{
	Super::DrawHUD();

	int32 CenterX = Canvas->SizeX / 2;
	int32 CenterY = Canvas->SizeY / 2;

	int32 UniX = Canvas->SizeX / 100;
	int32 DrawSize = UniX * 2;

	Draw2DLine(CenterX - DrawSize, CenterY, CenterX + DrawSize, CenterY, FColor::Green);
	Draw2DLine(CenterX, CenterY - DrawSize, CenterX , CenterY + DrawSize, FColor::Green);

}
