
import 'package:file_selector/file_selector.dart';
import 'package:flutter/material.dart';
import 'package:simple_printer_plug/simple_printer_plug.dart';

void main() {

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body:Center(

        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text('The simple_printer_plug is a test printer plug which only pop a windows native dialog to select printer.'),
            const Padding(
              padding: EdgeInsets.only(bottom: 20.0),
              child: Text('step 1: click select printer button.  \nstep 2:click select file button ,the app will freeze!'),
            ),

            ElevatedButton(onPressed: () {
              SimplePrinterPlug().selectPrinter().then((name) => print('printer name:$name'));
            }, child: const Text('select printer')),

            Padding(
              padding: const EdgeInsets.only(top: 30.0),
              child: ElevatedButton(onPressed: () {
                openFile(acceptedTypeGroups:[
                  const XTypeGroup(label: 'image (*.png)', extensions: ['png'])
                ],).then((value) => print('xfile:${value}'));
              }, child: const Text('select file')),
            )

          ],
        ),
      ),
    );
  }
}
