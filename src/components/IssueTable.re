[%bs.raw {|require('./IssueTable.css')|}];

let component = ReasonReact.reducerComponent("IssueTable");

type state = {issues: list(IssueType.issue)};

// let issuesData: list(IssueType.issue) = [
//   {
//     id: 1,
//     status: "Open",
//     owner: "Ravan",
//     created: "2016-08-15",
//     effort: 5,
//     completedDate: "undefined",
//     title: "Error in console when clicking Add",
//   },
//   {
//     id: 2,
//     status: "Assigned",
//     owner: "Eddie",
//     created: "2016-08-16",
//     effort: 14,
//     completedDate: "2016-08-30",
//     title: "Missing bottom border on panel",
//   },
// ];

let make = _children => {
  ...component,
  initialState: () => {
    issues: [
      {
        id: 1,
        status: "Open",
        owner: "Ravan",
        created: "2016-08-15",
        effort: 5,
        completedDate: "undefined",
        title: "Error in console when clicking Add",
      },
      {
        id: 2,
        status: "Assigned",
        owner: "Eddie",
        created: "2016-08-16",
        effort: 14,
        completedDate: "2016-08-30",
        title: "Missing bottom border on panel",
      },
    ],
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: self => {
    let issues = self.state;
    // let issueRows =
    // ReasonReact.array(
    //   Array.of_list(
    //     List.map(
    //       (issue: IssueType.issue) =>
    //         <IssueRow key={string_of_int(issue.id)} />,
    //       issuesData,
    //     ),
    //   ),
    // );
    <table>
      <thead>
        <tr>
          <th className="borderedStyle"> {ReasonReact.string("Id")} </th>
          <th className="borderedStyle"> {ReasonReact.string("Status")} </th>
          <th className="borderedStyle"> {ReasonReact.string("Owner")} </th>
          <th className="borderedStyle">
            {ReasonReact.string("Created On")}
          </th>
          <th className="borderedStyle"> {ReasonReact.string("Effort")} </th>
          <th className="borderedStyle">
            {ReasonReact.string("Completed On")}
          </th>
          <th className="borderedStyle"> {ReasonReact.string("Title")} </th>
        </tr>
      </thead>
      <tbody>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (issue: IssueType.issue) =>
                 <IssueRow key={string_of_int(issue.id)} issue />,
               issues,
             ),
           ),
         )}
      </tbody>
    </table>;
  },
};