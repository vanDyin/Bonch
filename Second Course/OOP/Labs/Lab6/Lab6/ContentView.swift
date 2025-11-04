import SwiftUI

struct ContentView: View {
    @Bindable var model = Model()
    
    var body: some View {
        VStack(alignment: .leading) {
            HStack {
                TextField("strLeft", text: $model.strLeft)
                    .font(.largeTitle)
                    .frame(maxWidth: 300)
                TextField("strRigth", text: $model.strRight)
                    .font(.largeTitle)
                    .frame(maxWidth: 300)
            }
            
            LazyHGrid(rows: [
                GridItem(.flexible(minimum: 75, maximum: 150)),
                GridItem(.flexible(minimum: 75, maximum: 150))
            ]) {
                createButton(label: "Clear Left", action: model.clearLeft)
                createButton(label: "Clear Right", action: model.clearRight)
                createButton(label: "Clear", action: model.clearAll)
                createButton(label: "Swap", action: model.swap)
                createButton(label: "Copy Left to Right", action: model.copyLeftToRight)
                createButton(label: "Copy Right to Left", action: model.copyRightToLeft)
            }
        }
        .padding()
    }
    
    func createButton(label: String, action: @escaping () -> Void) -> some View {
        Button(action: action) {
            ZStack {
                Text(label)
                    .font(.title)
                    .fontWeight(.medium)
                    .foregroundStyle(.white)
                    .padding()
                    .background(RoundedRectangle(cornerRadius: 20))
            }
        }
    }
}

#Preview {
    ContentView()
}
