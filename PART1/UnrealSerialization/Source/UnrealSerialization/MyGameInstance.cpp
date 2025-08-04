#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{

}

void UMyGameInstance::Init()
{
	Super::Init();

	//구조체 생성
	FStudentData RawDataSrc(16, TEXT("ppatabox"));

	//구조체 데이터를 파일로 저장 경로 설정
	// 프로젝트 디렉토리를 얻어오는 함수 사용해서 Saved 폴더를 묶어서 Saved 폴더 경로를 얻을 수 있다. (프로젝트 폴더에 Saved)
	const FString SavedDir = FPaths::Combine(FPlatformMisc::ProjectDir(), TEXT("Saved"));
	UE_LOG(LogTemp, Log, TEXT("저장할 파일 폴더 : %s"), *SavedDir);

	{
		//파일 이름 지정 
		const FString RawDataFileNmae(TEXT("RawData.bin"));
		// 해당 파일에 대한 전체 경로 , 파일에 대한 절대 경로 값을 얻을 수 있다.
		// 얻으면 폴더가 이상하게 나온다
		FString RawDataAbsolutePath = FPaths::Combine(*SavedDir, *RawDataAbsolutePath);
		UE_LOG(LogTemp, Log, TEXT("저장할 파일 전체 경로 : %s"), *RawDataAbsolutePath);
		
		// 해당 스트링을 보기 좋게 바꿔준다. 
		FPaths::MakeStandardFilename(RawDataAbsolutePath);
		UE_LOG(LogTemp, Log, TEXT("변경할 파일 전체 경로 : %s"), *RawDataAbsolutePath)

	}
}