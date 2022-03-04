
#include "MCAIE.h"

#include "ComponentVisualizers/Public/ComponentVisualizers.h"
#include "AIPawnSensingComponentVisualizer.h"
#include "../Sense/AIVisualizerInfo.h"
#define LOCTEXT_NAMESPACE "FMCAIEModule"

void FMCAIEModule::StartupModule()
{
	//不可用 LoadModuleChecked 并且加载周期在Editor之后
	bool isLoaded = FModuleManager::Get().IsModuleLoaded("ComponentVisualizers");
	if (isLoaded) {
		FComponentVisualizersModule& ComponentVisualizersModule = FModuleManager::GetModuleChecked<FComponentVisualizersModule>("ComponentVisualizers");

		if (ComponentVisualizersModule.SupportsDynamicReloading()) {
			ComponentVisualizersModule.RegisterComponentVisualizer(UAIVisualizerInfo::StaticClass()->GetFName(), MakeShareable(new FAIPawnSensingComponentVisualizer));
		}
	}

}

void FMCAIEModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMCAIEModule, MCAIE)